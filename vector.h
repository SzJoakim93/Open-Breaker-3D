#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

template <class T>
class vector
{
public:
    vector()
    {
        current_num = 0;
        max_num = 16;
        values = new T [max_num];
    }

    vector(const vector & other)
    {
        this->current_num = other.current_num;
        this->max_num = other.max_num;
        values = new T [max_num];
        for (int i=0; i<current_num; i++)
            this->values[i] = other.values[i];
    }

    vector & operator = (const vector & other)
    {
        delete [] values;
        this->current_num = other.current_num;
        this->max_num = other.max_num;
        values = new T [max_num];
        for (int i=0; i<current_num; i++)
            this->values[i] = other.values[i];
    }

    ~vector()
    {
        delete [] values;
        values = 0;
    }

    T & operator [] (const int & i)
    {
        return values[i];
    }

    const T & operator [] (const int & i) const
    {
        return values[i];
    }

    T & at(const int & i) const
    {
        return values[i];
    }

    void insert(const T & new_value)
    {
        if (current_num+1 > max_num)
        {
            max_num *= 2;
            T * temp = new T [max_num];
            for (int i=0; i<current_num; i++)
                temp[i] = values[i];
            delete [] values;
            values = temp;
        }

        values[current_num] = new_value;
        current_num++;
    }

    void replace(const int & i, const int & j)
    {
        T temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    void clear()
    {
        delete [] values;
        current_num = 0;
        max_num = 16;
        values = new T [max_num];
    }

    const int & size()
    {
        return current_num;
    }

private:
    T * values;
    int current_num;
    int max_num;
};

#endif // VECTOR_H_INCLUDED
