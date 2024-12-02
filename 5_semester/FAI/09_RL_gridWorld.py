import numpy as np
import random

class GridWorld:
    def __init__(self, grid, terminal_states, rewards, gamma=0.9):
        """
        Initialize the GridWorld environment.
        :param grid: A 2D list representing the grid world. 0 for empty cells, 1 for walls.
        :param terminal_states: List of terminal states (e.g., [(0, 3), (1, 3)]).
        :param rewards: Dictionary with rewards for specific states (e.g., {(0, 3): 1, (1, 3): -1}).
        :param gamma: Discount factor.
        """
        self.grid = grid
        self.n_rows, self.n_cols = len(grid), len(grid[0])
        self.terminal_states = terminal_states
        self.rewards = rewards
        self.gamma = gamma
        self.actions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right

    def is_valid_state(self, state):
        """Check if a state is valid (not a wall or out of bounds)."""
        x, y = state
        return 0 <= x < self.n_rows and 0 <= y < self.n_cols and self.grid[x][y] == 0

    def step(self, state, action):
        """
        Take a step in the environment.
        :param state: Current state as (x, y).
        :param action: Action to take as (dx, dy).
        :return: Next state, reward, and done (if terminal state is reached).
        """
        if state in self.terminal_states:
            return state, self.rewards.get(state, 0), True

        next_state = (state[0] + action[0], state[1] + action[1])
        if not self.is_valid_state(next_state):
            next_state = state  # If invalid, stay in the current state

        reward = self.rewards.get(next_state, 0)
        done = next_state in self.terminal_states
        return next_state, reward, done

    def get_all_states(self):
        """Get all valid states in the grid."""
        return [(i, j) for i in range(self.n_rows) for j in range(self.n_cols) if self.grid[i][j] == 0]

def q_learning(env, episodes=1000, alpha=0.1, gamma=0.9, epsilon=0.1):
    """
    Perform Q-Learning in the GridWorld.
    :param env: The GridWorld environment.
    :param episodes: Number of episodes for training.
    :param alpha: Learning rate.
    :param gamma: Discount factor.
    :param epsilon: Exploration rate for ε-greedy policy.
    :return: The learned Q-table.
    """
    # Initialize Q-table
    Q = {}
    for state in env.get_all_states():
        Q[state] = {action: 0 for action in env.actions}

    for episode in range(episodes):
        state = random.choice(env.get_all_states())
        done = False

        while not done:
            # Choose action (ε-greedy policy)
            if random.uniform(0, 1) < epsilon:
                action = random.choice(env.actions)  # Explore
            else:
                action = max(Q[state], key=Q[state].get)  # Exploit

            # Take a step
            next_state, reward, done = env.step(state, action)

            # Update Q-value
            max_next_q = max(Q[next_state].values()) if next_state not in env.terminal_states else 0
            Q[state][action] += alpha * (reward + gamma * max_next_q - Q[state][action])

            state = next_state  # Move to the next state

    return Q

def extract_policy(Q):
    """
    Extract the policy from the learned Q-table.
    :param Q: The Q-table.
    :return: A dictionary mapping states to optimal actions.
    """
    policy = {}
    for state, actions in Q.items():
        policy[state] = max(actions, key=actions.get)
    return policy

def print_policy(policy, env):
    """
    Print the policy in a grid-like format.
    :param policy: The policy dictionary.
    :param env: The GridWorld environment.
    """
    directions = {(-1, 0): '↑', (1, 0): '↓', (0, -1): '←', (0, 1): '→'}
    grid_policy = [[' ' for _ in range(env.n_cols)] for _ in range(env.n_rows)]

    for state, action in policy.items():
        x, y = state
        grid_policy[x][y] = directions.get(action, 'T')  # 'T' for terminal states

    for row in grid_policy:
        print(' '.join(row))

# Example Usage
if __name__ == "__main__":
    grid = [
        [0, 0, 0, 1],
        [0, 1, 0, 1],
        [0, 0, 0, 0]
    ]
    terminal_states = [(0, 3), (1, 3)]
    rewards = {(0, 3): 1, (1, 3): -1}
    env = GridWorld(grid, terminal_states, rewards)

    print("Training Q-Learning agent...")
    Q = q_learning(env, episodes=1000, alpha=0.1, gamma=0.9, epsilon=0.1)
    policy = extract_policy(Q)

    print("\nOptimal Policy:")
    print_policy(policy, env)
