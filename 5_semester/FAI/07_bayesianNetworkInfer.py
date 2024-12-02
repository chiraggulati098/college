# Import required libraries
from pgmpy.models import BayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

# Step 1: Define the Bayesian Network structure
# For example: A -> B -> C (A influences B, B influences C)
bayesian_model = BayesianNetwork([('A', 'B'), ('B', 'C')])

# Step 2: Define the CPDs (Conditional Probability Distributions)
# CPD for A (prior probability)
cpd_a = TabularCPD(variable='A', variable_card=2, values=[[0.6], [0.4]])

# CPD for B (conditional on A)
cpd_b = TabularCPD(variable='B', variable_card=2,
                    values=[[0.7, 0.2],  # P(B=0 | A=0), P(B=0 | A=1)
                            [0.3, 0.8]], # P(B=1 | A=0), P(B=1 | A=1)
                    evidence=['A'], evidence_card=[2])

# CPD for C (conditional on B)
cpd_c = TabularCPD(variable='C', variable_card=2,
                    values=[[0.9, 0.4],  # P(C=0 | B=0), P(C=0 | B=1)
                            [0.1, 0.6]], # P(C=1 | B=0), P(C=1 | B=1)
                    evidence=['B'], evidence_card=[2])

# Step 3: Add the CPDs to the model
bayesian_model.add_cpds(cpd_a, cpd_b, cpd_c)

# Validate the model
assert bayesian_model.check_model(), "The model is incorrect!"

# Step 4: Perform inference using Variable Elimination
# Initialize the inference object
inference = VariableElimination(bayesian_model)

# Example 1: Query the probability of C given A=1
query_result_1 = inference.query(variables=['C'], evidence={'A': 1})
print("P(C | A=1):")
print(query_result_1)

# Example 2: Query the probability of B given A=0
query_result_2 = inference.query(variables=['B'], evidence={'A': 0})
print("\nP(B | A=0):")
print(query_result_2)

# Example 3: Query the probability of A
query_result_3 = inference.query(variables=['A'])
print("\nP(A):")
print(query_result_3)

# Example 4: Query the probability of C given B=1
query_result_4 = inference.query(variables=['C'], evidence={'B': 1})
print("\nP(C | B=1):")
print(query_result_4)