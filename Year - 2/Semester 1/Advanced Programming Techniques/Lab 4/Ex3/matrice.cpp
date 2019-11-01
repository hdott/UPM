#include "matrice.h"


Matrice::Matrice(const Matrice & matrix){
    this->row = matrix.row;
    this->col = matrix.col;

    vect = new int*[row];
    for(int i = 0; i < row; ++i){
        vect[i] = new int[col];
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            vect[i][j] = matrix[i][j];
        }
    }
}

Matrice::~Matrice(){
    for(int i = 0; i < row; ++i){
        delete[] vect[i];
    }
    delete[] vect;
}

Matrice Matrice::operator+(const Matrice & matrix) const{
    if(row != matrix.row && col != matrix.col){
        std::cerr << "ERR [Matrix Addition]" << std::endl;
        std::cerr << "\tTwo matrices may be added only if" 
                << " they have the same dimension" << std::endl;

        exit(EXIT_FAILURE);
    }
    
    Matrice x(row, col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            x[i][j] = vect[i][j] + matrix[i][j];
        }
    }

    return x;
}

Matrice Matrice::operator-(const Matrice & matrix) const{
    if(row != matrix.row && col != matrix.col){
        std::cerr << "ERR [Matrix Substraction]" << std::endl;
        std::cerr << "\tTwo matrices may be subtracted only if" 
                << " they have the same dimension" << std::endl;

        exit(EXIT_FAILURE);
    }
    
    Matrice x(row, col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            x[i][j] = vect[i][j] - matrix[i][j];
        }
    }

    return x;
}

Matrice Matrice::operator*(const Matrice & matrix) const{
    if(col != matrix.row){
        std::cerr << "ERR [Matrix Multiplication]" << std::endl;
        std::cerr << "\tMatrix Multiplication requires m1(m X n) m2(n x k)"
                << std::endl;

        exit(EXIT_FAILURE);
    }

    Matrice tmp(row, matrix.col);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < matrix.col; ++j)
            for(int x = 0; x < col; ++x)
                tmp[i][j] += vect[i][x] * matrix[x][j];

    return tmp;
}

// Matrice Matrice::operator/(const Matrice &) const{}

Matrice Matrice::operator+(const int n) const{
    Matrice tmp(row, col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            tmp[i][j] = vect[i][j] + n;
        }
    }

    return tmp;
}

Matrice Matrice::operator-(const int n) const{
    Matrice tmp(row, col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            tmp[i][j] = vect[i][j] - n;
        }
    }

    return tmp;
}

Matrice Matrice::operator*(const int n) const{
    Matrice tmp(row, col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            tmp[i][j] = vect[i][j] * n;
        }
    }

    return tmp;
}

Matrice Matrice::operator/(const int n) const{
    Matrice tmp(row, col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            tmp[i][j] = vect[i][j] / n;
        }
    }

    return tmp;
}
        
// bool Matrice::operator<(const Matrice &) const{}

// bool Matrice::operator>(const Matrice &) const;
// bool Matrice::operator<=(const Matrice &) const;
// bool Matrice::operator>=(const Matrice &) const;
        
bool Matrice::operator!=(const Matrice & m) const{
    if(row != m.row || col != m.col){
        return true;
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(vect[i][j] != m[i][j]){
                return true;
            }
        }
    }

    return false;
}

bool Matrice::operator==(const Matrice & m) const{
    if(row != m.row || col != m.col){
        return false;
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(vect[i][j] != m[i][j]){
                return false;
            }
        }
    }

    return true;
}
    
Matrice & Matrice::operator+=(const Matrice & m){

    return (*this = *this + m);
}

Matrice & Matrice::operator-=(const Matrice & m){
    return (*this = *this - m);
}

Matrice & Matrice::operator*=(const Matrice & m){
    return (*this = *this * m);
}

// Matrice operator/=(const Matrice &) const;

Matrice & Matrice::operator+=(const int n){
    return (*this = *this + n);
}

Matrice & Matrice::operator-=(const int n){
    return (*this = *this - n);
}

Matrice & Matrice::operator*=(const int n){
    return (*this = *this * n);
}
        
Matrice & Matrice::operator/=(const int n){
    return (*this = *this / n);
}

Matrice Matrice::operator++(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            ++vect[i][j];
        }
    }

    return *this;
}

Matrice Matrice::operator++(int n){
    Matrice tmp(*this);

    if(n == 0){
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                vect[i][j]++;
            }
        }
    } else{
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                (vect[i][j]) += n;
            }
        }
    }

    return tmp;
}

Matrice Matrice::operator--(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            --(vect[i][j]);
        }
    }

    return *this;
}

Matrice Matrice::operator--(int n){
    Matrice tmp(*this);

    if(n == 0){
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                (vect[i][j])--;
            }
        }
    } else{
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                (vect[i][j]) -= n;
            }
        }
    }

    return tmp;
}

Matrice & Matrice::operator=(const Matrice & m){
    // if(row != m.row || col != m.col){
    //     std::cerr << "ERR [Matrix Assignment]" << std::endl;
    //     std::cerr << "\tMatrix Assignment requires for both matrices to have" 
    //             << " the same dimension m1(m X n) m2(m x n)"
    //             << std::endl;

    //     exit(EXIT_FAILURE);
    // }

    for(int i = 0; i < row; ++i){
        delete[] vect[i];
    }
    delete[] vect;

    this->row = m.row;
    this->col = m.col;

    vect = new int*[row];
    for(int i = 0; i < row; ++i){
        vect[i] = new int[col];
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            vect[i][j] = m[i][j];
        }
    }

    return *this;
}

int* Matrice::operator[](int x) const{
    if(x > row || x < 0){
        return nullptr;
    }
    
    return vect[x];
}

        // friend Matrice operator+(const Matrice &, const Matrice &);
        // friend Matrice operator-(const Matrice &, const Matrice &);
        // friend Matrice operator*(const Matrice &, const Matrice &);
        // friend Matrice operator/(const Matrice &, const Matrice &);
Matrice operator+(const int n, const Matrice & m){
    return m + n;
}

Matrice operator-(const int n, const Matrice & m){
    Matrice tmp(m.row, m.col);

    for(int i = 0; i < m.row; ++i){
        for(int j = 0; j < m.col; ++j){
            tmp[i][j] = n - m.vect[i][j];
        }
    }

    return tmp;
}

Matrice operator*(const int n, const Matrice & m){
    return m * n;
}

// Matrice operator/(const int n, const Matrice &);
// Matrice operator+=(const Matrice & m1, const Matrice & m2)
// Matrice operator-=(const Matrice &, const Matrice &);
// Matrice operator*=(const Matrice &, const Matrice &);
// Matrice operator/=(const Matrice &, const Matrice &);
// Matrice operator+=(const int, const Matrice &);
// Matrice operator-=(const int, const Matrice &);
// Matrice operator*=(const int, const Matrice &);
// Matrice operator/=(const int, const Matrice &);

std::ostream & operator<<(std::ostream & os, const Matrice & m){
    for(int i = 0; i < m.row; ++i){
        for(int j = 0; j < m.col; ++j){
            os << m.vect[i][j] << " ";
        }
        os << std::endl;
    }

    return os;
}

std::istream & operator>>(std::istream & is, const Matrice & m){
    std::cout << "Enter the number of rows and collumns: ";
    std::cin >> m.row >> m.col;

    for(int i = 0; i < m.row; ++i){
        for(int j = 0; j < m.col; ++j){
            is >> m.vect[i][j];
        }
    }

    return is;
}