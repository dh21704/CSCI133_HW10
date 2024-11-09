#include <iostream>
#include <string>
using namespace std;

template <typename T>
class CPersonInfo
{
  public:
  
  //constructors 
  CPersonInfo();
  CPersonInfo(const CPersonInfo &other);
  CPersonInfo(T weight, T height, int age, string fullname);
  ~CPersonInfo();
  
  T GetWeight() const;
  T GetHeight() const;
  int GetAge() const;
  string GetName() const;
  int GetNameLength() const;
  void SetWeight(T weight);
  void SetHeight(T height);
  void SetAge(int age);
  void SetName(string fulName);
  
  private:
  
  T m_weight;
  T m_height;
  int *m_age;
  string m_fullName;
};

template <typename T>
CPersonInfo<T>::CPersonInfo()
{
    m_weight = 0;
    m_height = 0;
    m_age = new int(0);
    m_fullName = "Default";
}

template <typename T>
CPersonInfo<T>::CPersonInfo(const CPersonInfo &other)
{
    m_weight = other.m_weight;
    m_height = other.m_height;
    m_age = new int(*other.m_age);
    m_fullName = other.m_fullName;
}

template <typename T>
CPersonInfo<T>::CPersonInfo(T weight, T height, int age, string fullName)
{
    m_weight = weight;
    m_height = height;
    m_fullName = fullName;
    m_age = new int(age);
}

template <typename T>
CPersonInfo<T>::~CPersonInfo()
{
    delete m_age;
}

template <typename T>
T CPersonInfo<T>::GetWeight() const
{
    return m_weight;
}

template <typename T>
T CPersonInfo<T>::GetHeight() const
{
    return m_height;
}

template <typename T>
int CPersonInfo<T>::GetAge() const{
    return *m_age;
}

template <typename T>
string CPersonInfo<T>::GetName() const
{
    return m_fullName;
}

template <typename T>
int CPersonInfo<T>::GetNameLength() const 
{
    int counter = 0;
    
    for (unsigned int i = 0; i < m_fullName.size(); i++)
    {
        counter++;
    }
    
    return counter;
}

template <typename T>
void CPersonInfo<T>::SetWeight(T weight)
{
    m_weight = weight;
}

template <typename T>
void CPersonInfo<T>::SetHeight(T height)
{
    m_height = height;
}

template <typename T>
void CPersonInfo<T>::SetAge(int age)
{
    m_age = new int(age);
}

template <typename T>
void CPersonInfo<T>::SetName(string fullName)
{
    m_fullName = fullName;
}


template <typename ObjType>
void DisplayInfo(const ObjType &obj)
{
    cout << "\nName: " << obj.GetName();
    cout << "\nAge: " << obj.GetAge();
    cout << "\nHeight: " << obj.GetHeight();
    cout << "\nWeight: " << obj.GetWeight();
}

int main()
{
    CPersonInfo <int> P1;
    
    CPersonInfo <double> P2(250.3, 54.1, 90, "John Pork");
    
    CPersonInfo <double> P3(P2);
    
    int weight;
    int age;
    int height;
    string name;
    
    void(*functionPtr)(const CPersonInfo<double>&) = &DisplayInfo;
    
    cout << "P1 = \n";
    DisplayInfo(P1);
    
    //get info from users to update P1
    cout << "\n\n\n\nName: ";
    getline(cin, name);
    cout << "\nAge: ";
    cin >> age;
    cout << "\nHeight: ";
    cin >> height;
    cout << "\nWeight: ";
    cin >> weight;
    
    //update p1 
    P1.SetHeight(height);
    P1.SetWeight(weight);
    P1.SetAge(age);
    P1.SetName(name);
    
    cout << "\nP1 = \n";
    DisplayInfo(P1);
    
    cout << "\nP2 = \n";
    DisplayInfo(P2);
    
    cout << "\nP3 = \n";
    (*functionPtr)(P3);
    
    
    cout << "hello";
    
    return 0;
}

