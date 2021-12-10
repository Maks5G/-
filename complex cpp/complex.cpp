#include "complex.h"
#include <chrono>

class Complex {
    private:
        double real, imaginary, modul;
        long double argument;
    public:
        Complex() {}

        Complex(double re, double im) {
            real = re;
            imaginary = im;
        }

        void get(){
            std::cout << "Введіть дійсну частину: " << std::endl;
            std::cin >> real;
            std::cout << "Введіть уявну частину: " << std::endl;
            std::cin >> imaginary;
        }

        void get(double real, double imaginary){
            this->real = real;
            this->imaginary = imaginary;
        }

        int check(){
            if(imaginary==0 && real==0)
                return 1;
            else if(imaginary==0 && real<0)
                return 2;
            else if(imaginary==0 && real>0)
                return 3;
            return 0;
        }
        
        void argumentz(){ // визначаємо кут комплексного числа
            if(real>0 && imaginary>=0){
                argument = atan(imaginary/real);
            }
            else if(real<0 && imaginary>=0){
                argument = M_PI - atan(std::abs(imaginary/real));
            }
            else if(real<0 && imaginary<0){
                argument = M_PI + atan(std::abs(imaginary/real));
            }
            else if(real>0 && imaginary<0){
                argument = 2*M_PI - atan(std::abs(imaginary/real));
            }
            else if(real==0 && imaginary>0){
                argument = M_PI_2;
            }
            else if(real==0 && imaginary<0){
                argument = 3*M_PI_2;
            }
            modul = sqrt(real*real + imaginary*imaginary);
        }

        Complex dilutu(double a){
            Complex temp;
            temp.real = real/a;
            temp.imaginary = imaginary/a;
            return temp;
        }

        Complex mnozh(double a){
            Complex temp;
            temp.real = real*a;
            temp.imaginary = imaginary*a;
            return temp;
        }

        double retre(double st){
            double new_modul;
            new_modul = pow(modul, st);
            double new_re = new_modul*cos(st*argument + st*2.*M_PI);
            return new_re;
        }

        double retim(double st){
            double new_modul;
            new_modul = pow(modul, st);
            double new_im = new_modul*sin(st*argument - st*2.*M_PI);
            if(new_im < 0.01){
                new_im = 0.0;
            }
            return new_im;
        }

        Complex newz(double st){
            argumentz();
            Complex temp;
            double new_modul;
            new_modul = pow(modul, st);
            double co, si;
            double new_im = new_modul*sin(st*argument - st*2*M_PI);
            double new_re = new_modul*cos(st*argument + st*2*M_PI);
            co = cos(st*argument + st*2*M_PI);
            si = sin(st*argument - st*2*M_PI);
            if(si < 0.00001 && co >0.9998){
                new_im = 0.0;
                new_re = new_modul;
            }
            if(si < 0.00001 && co <-0.9998){
                new_im = 0.0;
                new_re = -new_modul;
            }
            if(si > 0.9998 && co < 0.0001){
                new_im = new_modul;
                new_re = 0.0;
            }
            if(si < -0.9998 && co < 0.0001){
                new_im = new_modul;
                new_re = 0.0;
            }
            
            temp.get(new_re, new_im);
            return temp;
        }

        Complex operator+(Complex op2);
        Complex operator*(Complex op2);
        Complex operator/(Complex op2);
        Complex operator-(Complex op2);
        Complex operator=(Complex op2);
        Complex operator-() const;

        friend std::ostream& operator<< (std::ostream &out, const Complex &complex);
        friend std::istream& operator>> (std::istream &in, Complex &complex);

};
 
Complex Complex::operator-() const{
    Complex temp;
    temp.imaginary = -imaginary;
    temp.real = -real;
    return temp;
}

Complex Complex::operator+(Complex op2){
    Complex temp;

    temp.real = op2.real + real;
    temp.imaginary = op2.imaginary + imaginary;

    return temp;
}

Complex Complex::operator*(Complex op2){
    Complex temp;

    temp.real = op2.real * real - op2.imaginary * imaginary;
    temp.imaginary = op2.imaginary * real + imaginary* op2.real;

    return temp;
}

Complex Complex::operator/(Complex op2){
    Complex temp;

    temp.real = (op2.real * real + op2.imaginary * imaginary)/(op2.real * op2.real + op2.imaginary * op2.imaginary);
    temp.imaginary = (op2.imaginary * real - imaginary * op2.real)/(op2.real * op2.real + op2.imaginary * op2.imaginary);

    return temp;
}

Complex Complex::operator-(Complex op2){
    Complex temp;
    temp.real = real - op2.real;
    temp.imaginary = imaginary - op2.imaginary;
    
    return temp;
}

Complex Complex::operator=(Complex op2){

    real = op2.real;
    imaginary = op2.imaginary;
    
    return *this;
}

std::ostream& operator<< (std::ostream &out, const Complex &complex){
    out << complex.real;
    if(complex.imaginary > 0){
        out << " + i" << complex.imaginary << std::endl;
    } else if(complex.imaginary < 0){
        out << " - i" << -complex.imaginary << std::endl;
    }
    return out;
}

std::istream& operator>> (std::istream &in, Complex &complex){
    std::cout << "Введіть дійсну частину: " << std::endl;
    in >> complex.real;
    std::cout << "Введіть уявну частину: " << std::endl;
    in >> complex.imaginary;

    return in;
}

//void quadric(Complex a, Complex b, Complex c)
void quadric(std::complex<double> a, std::complex<double> b, std::complex<double> c)
{
    auto start = std::chrono::high_resolution_clock::now();
    //свій клас
    /*
    Complex  x1, x2;
    Complex D = (b*b - (a*c + a*c + a*c + a*c));
    int t = D.check();
    if(t==1){
        Complex x = -b/(a+a);
        std::cout << "X: " << x << std::endl;
    } else{
        Complex Dn;
        Dn = D.newz(1./2.);
        x1 = (-b + Dn)/(a+a);
        x2 = (-b - Dn)/(a+a);
        std::cout << "X1: " << x1 << std::endl;
        std::cout << "X2: " << x2 << std::endl;
    } */

    //бібліотека
    
    std::complex <double> D;
    D = (b*b - (a*c + a*c + a*c + a*c));
    std::complex <double> x1 = (-b + sqrt(D))/(a+a);
    std::complex <double> x2 = (-b - sqrt(D))/(a+a);
    std::cout << "X1: " << x1 << std::endl;
    std::cout << "X2: " << x2 << std::endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "Duration: " << duration.count() << "s" << std::endl;
}

std::complex<double> cubic(std::complex<double> a,std::complex<double> b,std::complex<double> c,std::complex<double> d)
//Complex cubic(Complex a, Complex b, Complex c, Complex d)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    std::complex<double> a1 = a;
    std::complex<double> b1 = b;
    b = b/a;
    c = c/a;
    d = d/a;
    a = a/a;
    std::complex<double> p(c.real() - (pow(b.real(), 2)/3), c.imag() - (pow(b.imag(), 2)/3));            //Complex p = c - (pow(b, 2)/3);
    std::complex<double> q(d.real() + (2*pow(b.real(), 3)/27) - (c.real()*b.real()/3), d.imag() + (2*pow(b.imag(), 3)/27) - (c.imag()*b.imag()/3));    // / / // /Complex q = d + (2*pow(b, 3)/27) - (c*b/3);
    std::complex<double> D(pow(q.real(), 2)/4 + pow(p.real(), 3)/27, pow(q.imag(), 2)/4 + pow(p.imag(), 3)/27);        //Complex D = pow(q, 2)/4 + pow(p, 3)/27;
    std::complex<double> D1 = -D;
    std::complex<double> q1(-q.real()/2, -q.imag()/2);
    std::complex<double> y1, y2, y3, x1, x2, x3, al, be;

    std::complex<double> e1(-0.5, sqrt(3)/2);
    std::complex<double> e2(-0.5, -sqrt(3)/2);

    al = pow(q1 + sqrt(D), 1./3.);
    be = pow(q1 - sqrt(D), 1./3.);

    y1 = pow(q1 + sqrt(D), 1./3.) + pow(q1 - sqrt(D), 1./3.);
    y2 = e1*al + e2*be;
    y3 = e2*al + e1*be;

    x1 = y1 - b1/(a1 + a1 + a1);
    x2 = y2 - b1/(a1 + a1 + a1);
    x3 = y3 - b1/(a1 + a1 + a1);

    std::cout << "X1 = " << x1 << std::endl;
    std::cout << "X2 = " << x2 << std::endl;
    std::cout << "X3 = " << x3 << std::endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "Duration: " << duration.count() << "s" << std::endl;
    return x1;
    
} 

void ferrari(std::complex<double> a, std::complex<double> b, std::complex<double> c, std::complex<double> d, std::complex<double> e){
    auto start = std::chrono::high_resolution_clock::now();
    std::complex<double> a1 = a;
    std::complex<double> b1 = b;
    b = b/a;
    c = c/a;
    d = d/a;
    e = e/a;
    a = 1;

    std::complex<double> p(c.real()-3*pow(b.real(), 2)/8, c.imag()-3*pow(b.imag(), 2)/8);
    std::complex<double> q(pow(b.real(), 3)/8 - c.real()*b.real()/2 + d.real(), pow(b.imag(), 3)/8 - c.imag()*b.imag()/2 + d.imag());
    std::complex<double> r(-3*pow(b.real(), 4)/256 + pow(b.real(), 2)*c.real()/16 - d.real()*b.real()/4 + e.real(), -3*pow(b.imag(), 4)/256 + pow(b.imag(), 2)*c.imag()/16 - d.imag()*b.imag()/4 + e.imag()); // убрали кубічний член

    std::cout << "Спочатку розв'яжемо кубічний дискримінант і знайдемо 1 цілий корінь... " << std::endl;
    std::complex<double> temp(2, 0);
    std::complex<double> qt(pow(q.real(), 2)/4, pow(q.imag(), 2)/4);

    std::complex<double> s = cubic(temp, -p, -r-r, r*p - qt); // розв'язали дискримінант 3-го степеня
    std::cout << "Отже корінь: " << s << std::endl;
    std::complex<double> j = sqrt(s+s-p);
    std::complex<double> k1 = q/(j+j) + s;
    std::complex<double> k2 = -q/(j+j) + s;
    std::complex<double> D1 = pow(j, 2) - k1 - k1 - k1 - k1;
    std::complex<double> D2 = pow(j, 2) - k2 - k2 - k2 - k2;
    std::complex<double> x1, x2, x3, x4, y1, y2, y3, y4;

    y1 = (j+sqrt(D1))/temp;
    y2 = (j-sqrt(D1))/temp;
    y3 = (-j+sqrt(D2))/temp;
    y4 = (-j-sqrt(D2))/temp;

    std::complex<double> bp(b.real()/4, b.imag()/4);

    x1 = y1 - bp;
    x2 = y2 - bp;
    x3 = y3 - bp;
    x4 = y4 - bp;

    std::cout << "X1: " << x1 << std::endl;
    std::cout << "X2: " << x2 << std::endl;
    std::cout << "X3: " << x3 << std::endl;
    std::cout << "X4: " << x4 << std::endl;
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "Duration: " << duration.count() << "s" << std::endl;
}

