%P6 - Linear Regression

db = readtable('USA_Housing.csv');  % reading the dataset
db = removevars(db,"Address");  % removing text based column as our Model doesn't require it

predictors = db(:, {'Avg_AreaIncome', 'Avg_AreaHouseAge', 'Avg_AreaNumberOfRooms', ...
    'Avg_AreaNumberOfBedrooms', 'AreaPopulation'});     % columns helping with prediction
response = db.Price;  % Target Column

rng (101);  % setting custom rng for replicatbility

test_percentage = 0.20;

idx = randperm(size(db, 1));
num_test = round(test_percentage * numel(idx));

training_data = predictors(idx(num_test+1:end), :);
testing_data = predictors(idx(1:num_test), :);

training_response = response(idx(num_test+1:end), :);
testing_response = response(idx(1:num_test), :);

model = fitlm(training_data, training_response); % train model

disp('Linear Regression Model Details:');
disp(model);