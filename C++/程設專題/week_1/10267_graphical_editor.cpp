#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point(int, int);
    void swap_with(Point&);
    bool operator>(const Point&);
    Point operator+(const Point&);
};

class Graph : protected vector<vector<char>> {
private:
    int width, height;

protected:
    int serial(const Point&);

public:
    Graph();
    Graph(int, int);
    void clear();
    void set(const Point&, char);
    char get(const Point&);
    void draw(Point, Point, char);
    void fill(const Point&, char);
    friend ostream& operator<<(ostream&, const Graph&);
};

vector<string> split(string &str, char delimiter) {
    vector<string> result;
    while (true) {
        size_t pos = str.find(delimiter);
        if (pos == string::npos) {
            result.emplace_back(str);
            break;
        }

        result.emplace_back(str.substr(0, pos));
        str = str.substr(pos + 1);
    }
    return result;
}

int main() {
    Graph graph;
    bool exit_signal = false;
    string command;
    while (!exit_signal && getline(cin, command)) {
        auto args = split(command, ' ');
        switch(args[0][0]) {
            case 'I':
                graph = Graph(stoi(args[1]), stoi(args[2]));
                break;
            case 'C':
                graph.clear();
                break;
            case 'L':
                graph.set(Point(stoi(args[1]) - 1, stoi(args[2]) - 1),
                          args[3][0]);
                break;
            case 'V':
                graph.draw(Point(stoi(args[1]) - 1, stoi(args[2]) - 1),
                           Point(stoi(args[1]) - 1, stoi(args[3]) - 1),
                           args[4][0]);
                break;
            case 'H':
                graph.draw(Point(stoi(args[1]) - 1, stoi(args[3]) - 1),
                           Point(stoi(args[2]) - 1, stoi(args[3]) - 1),
                           args[4][0]);
                break;
            case 'K':
                graph.draw(Point(stoi(args[1]) - 1, stoi(args[2]) - 1),
                           Point(stoi(args[3]) - 1, stoi(args[4]) - 1),
                           args[5][0]);
                break;
            case 'F':
                graph.fill(Point(stoi(args[1]) - 1, stoi(args[2]) - 1),
                           args[3][0]);
                break;
            case 'S':
                cout << args[1] << "\n" << graph;
                break;
            case 'X':
                exit_signal = true;
                break;
            default:
                break;
        }
    }
    return 0;
}

Point::Point(int _x, int _y) :
    x(_x), y(_y) {}

void Point::swap_with(Point &other) {
    swap(x, other.x);
    swap(y, other.y);
}

bool Point::operator>(const Point& other) {
    if (x > other.x) return true;
    else if (x == other.x) {
        if (y > other.y) return true;
        else return false;
    }
    return false;
}

Point Point::operator+(const Point& other) {
    return Point(x + other.x, y + other.y);
}

Graph::Graph() :
    Graph(0, 0) {}

Graph::Graph(int _width, int _height) :
    vector<vector<char>>(_height, vector<char>(_width, 'O')),
    width(_width),
    height(_height) {}

int Graph::serial(const Point& p) {
    return p.y * width + p.x;
}

void Graph::clear() {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            (*this)[i][j] = 'O';
}

void Graph::set(const Point& position, char c) {
    (*this)[position.y][position.x] = c;
}

char Graph::get(const Point& position) {
    return (*this)[position.y][position.x];
}

void Graph::draw(Point start, Point end, char c) {
    if (start > end)
        start.swap_with(end);
    for (int i = start.y; i <= end.y; i++)
        for (int j = start.x; j <= end.x; j++)
            (*this)[i][j] = c;
}

void Graph::fill(const Point& position, char c) {
    const char original = (*this)[position.y][position.x];
    const vector<Point> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<bool> visited(width * height, false);
    function<void(Point)> dfs = [&](Point p) {
        if (p.x < 0 || p.y < 0 || p.x >= width || p.y >= height)
            return;
        const int index = serial(p);
        if (visited[index] || get(p) != original)
            return;
        visited[index] = true;
        set(p, c);
        for (auto &direction : directions)
            dfs(p + direction);
    };
    dfs(position);
}

ostream& operator<<(ostream& os, const Graph& graph) {
    for (int i = 0; i < graph.height; i++) {
        for (int j = 0; j < graph.width; j++)
            os << graph[i][j];
        os << "\n";
    }
    return os;
}