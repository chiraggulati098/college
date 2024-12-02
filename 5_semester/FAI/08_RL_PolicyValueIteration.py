import numpy as np

class GridWorld:
    def __init__(self, grid, terminal_states, transition_prob=1.0, gamma=0.9, rewards=None):
        """
        Initialize the Grid World environment.
        :param grid: A 2D list representing the grid world. 0 for empty cells, 1 for walls.
        :param terminal_states: List of terminal states (e.g., [(0, 0), (2, 2)]).
        :param transition_prob: Probability of intended direction.
        :param gamma: Discount factor.
        :param rewards: Dictionary with rewards for specific states (e.g., {(0, 0): 1, (2, 2): -1}).
        """
        self.grid = grid
        self.n_rows, self.n_cols = len(grid), len(grid[0])
        self.terminal_states = terminal_states
        self.transition_prob = transition_prob
        self.gamma = gamma
        self.rewards = rewards if rewards else {}
        self.actions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right

    def is_valid_state(self, state):
        """Check if a state is valid (not a wall or out of bounds)."""
        x, y = state
        return 0 <= x < self.n_rows and 0 <= y < self.n_cols and self.grid[x][y] == 0

    def get_next_states(self, state, action):
        """Get possible next states and their probabilities."""
        if state in self.terminal_states:
            return [(state, 1.0)]
        next_state = (state[0] + action[0], state[1] + action[1])
        if self.is_valid_state(next_state):
            return [(next_state, self.transition_prob)]
        return [(state, 1.0)]  # Stay in place if hitting a wall or out of bounds

    def get_reward(self, state):
        """Get the reward for a state."""
        return self.rewards.get(state, 0)

    def get_all_states(self):
        """Get all valid states."""
        return [(i, j) for i in range(self.n_rows) for j in range(self.n_cols) if self.grid[i][j] == 0]


def value_iteration(env, theta=1e-6):
    """Perform Value Iteration on the Grid World."""
    V = np.zeros((env.n_rows, env.n_cols))
    while True:
        delta = 0
        for state in env.get_all_states():
            if state in env.terminal_states:
                continue
            v = V[state]
            action_values = []
            for action in env.actions:
                next_states = env.get_next_states(state, action)
                value = sum(prob * (env.get_reward(ns) + env.gamma * V[ns]) for ns, prob in next_states)
                action_values.append(value)
            V[state] = max(action_values)
            delta = max(delta, abs(v - V[state]))
        if delta < theta:
            break
    # Derive policy from value function
    policy = np.zeros((env.n_rows, env.n_cols), dtype=(int, 2))
    for state in env.get_all_states():
        if state in env.terminal_states:
            continue
        action_values = []
        for action in env.actions:
            next_states = env.get_next_states(state, action)
            value = sum(prob * (env.get_reward(ns) + env.gamma * V[ns]) for ns, prob in next_states)
            action_values.append(value)
        policy[state] = env.actions[np.argmax(action_values)]
    return V, policy


def policy_iteration(env):
    """Perform Policy Iteration on the Grid World."""
    policy = np.zeros((env.n_rows, env.n_cols), dtype=(int, 2))
    V = np.zeros((env.n_rows, env.n_cols))

    def policy_evaluation(policy, theta=1e-6):
        while True:
            delta = 0
            for state in env.get_all_states():
                if state in env.terminal_states:
                    continue
                v = V[state]
                action = tuple(policy[state])
                next_states = env.get_next_states(state, action)
                V[state] = sum(prob * (env.get_reward(ns) + env.gamma * V[ns]) for ns, prob in next_states)
                delta = max(delta, abs(v - V[state]))
            if delta < theta:
                break

    while True:
        # Policy Evaluation
        policy_evaluation(policy)
        # Policy Improvement
        policy_stable = True
        for state in env.get_all_states():
            if state in env.terminal_states:
                continue
            old_action = tuple(policy[state])
            action_values = []
            for action in env.actions:
                next_states = env.get_next_states(state, action)
                value = sum(prob * (env.get_reward(ns) + env.gamma * V[ns]) for ns, prob in next_states)
                action_values.append(value)
            best_action = env.actions[np.argmax(action_values)]
            policy[state] = best_action
            if old_action != tuple(best_action):
                policy_stable = False
        if policy_stable:
            break
    return V, policy


# Example Usage
if __name__ == "__main__":
    grid = [
        [0, 0, 0, 1],
        [0, 1, 0, 1],
        [0, 0, 0, 0]
    ]
    terminal_states = [(0, 3), (1, 3)]
    rewards = {(0, 3): 1, (1, 3): -1}
    env = GridWorld(grid, terminal_states, rewards=rewards)

    print("Value Iteration:")
    V_vi, policy_vi = value_iteration(env)
    print("Value Function:")
    print(V_vi)
    print("Policy (action taken at each state):")
    print(policy_vi)

    print("\nPolicy Iteration:")
    V_pi, policy_pi = policy_iteration(env)
    print("Value Function:")
    print(V_pi)
    print("Policy (action taken at each state):")
    print(policy_pi)