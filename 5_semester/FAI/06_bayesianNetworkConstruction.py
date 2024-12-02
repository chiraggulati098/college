from pgmpy.models import BayesianNetwork
from pgmpy.factors.discrete import TabularCPD
from pgmpy.inference import VariableElimination

# Step 1: Define the structure of the Bayesian Network
# We will define a simple network: A -> B -> C (A causes B, and B causes C)
bayesian_model = BayesianNetwork([('A', 'B'), ('B', 'C')])

# Step 2: Define the Conditional Probability Distributions (CPDs)
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

# Check if the model is valid
assert bayesian_model.check_model()

# Step 4: Perform inference
# We will use Variable Elimination for inference
inference = VariableElimination(bayesian_model)

# Query the network (e.g., P(C | A=1))
result = inference.query(variables=['C'], evidence={'A': 1})
print(result)

# Query another example: P(B | A=0)
result_b = inference.query(variables=['B'], evidence={'A': 0})
print(result_b)