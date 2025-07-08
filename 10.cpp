#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <locale>
#include <iomanip>

using namespace std;

vector<vector<double>> createTournamentMatrix(int n) {
    vector<vector<double>> matrix(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << "Введите результат матча между участником " << i + 1 << " и участником " << j + 1 << " (1, 0 или 0.5): ";
            double result;
            cin >> result;
            matrix[i][j] = result;
            matrix[j][i] = 1 - result;
            if (result == 0.5) {
                matrix[j][i] = 0.5;
            }
        }
    }
    return matrix;
}

void saveMatrixToFile(const vector<vector<double>>& matrix, const string& filename) {
    ofstream out(filename);
    for (const auto& row : matrix) {
        for (double val : row) {
            out << val << " ";
        }
        out << endl;
    }
    cout << "Матрица турнира сохранена в файл: " << filename << endl;
}

int determineWinner(const vector<vector<double>>& matrix) {
    vector<double> scores(matrix.size(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            scores[i] += matrix[i][j];
        }
    }
    return max_element(scores.begin(), scores.end()) - scores.begin() + 1;
}

vector<int> rankParticipants(const vector<vector<double>>& matrix) {
    vector<pair<double, int>> scores;
    for (int i = 0; i < matrix.size(); ++i) {
        double score = 0;
        for (int j = 0; j < matrix.size(); ++j) {
            score += matrix[i][j];
        }
        scores.emplace_back(score, i + 1);
    }
    sort(scores.begin(), scores.end(), [](const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
    });
    vector<int> ranks;
    for (const auto& p : scores) {
        ranks.push_back(p.second);
    }
    return ranks;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    int n;
    cout << "Введите количество участников: ";
    cin >> n;
    auto matrix = createTournamentMatrix(n);
    saveMatrixToFile(matrix, "tournament_matrix.txt");
    int winner = determineWinner(matrix);
    cout << "Победитель: участник " << winner << endl;
    auto ranks = rankParticipants(matrix);
    cout << "Ранжирование участников: ";
    for (int r : ranks) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}