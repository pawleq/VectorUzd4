# VectorUzd4

Vector container

# Funkcijos

    iterator erase(iterator pointer)
    {
        size_type del;
        for (size_type i = 0; i < size_; ++i)
        {
            if (&Data_[i] == pointer)
                del = i;
        }
        for (size_type i = del; i < size_; i++)
        {
            Data_[i] = Data_[i + 1];
        }
        Data_[size_].~value_type();
        size_ = size_ - 1;
        return &Data_[del];
    }
    
Erase funkcija, kuri istrina nari i kuri yra paduodamas **pointer**, o tada perstumia tolimesnius narius viena vieta atgal

    void resize(size_type rsize)
    {
        if (rsize < 0)
            throw std::out_of_range {"in function Vector::resize"};
        if (rsize < size_)
        {
            pointer temp;
            temp = new value_type[rsize];
            for (auto i = 0; i < rsize; i++)
            {
                temp[i] = Data_[i];
            }
            Data_ = temp;
            temp = nullptr;
            size_ = rsize;

        }
        else if (rsize == capacity_)
        {
            pointer temp;
            temp = new value_type[rsize];
            for (auto i = 0; i < size_; i++)
            {
                temp[i] = Data_[i];
            }
            size_ = rsize;
            delete [] Data_;
            Data_ = temp;
            temp = nullptr;
        }
        if (rsize > capacity_)
        {
            reserve(capacity_);
            pointer temp;
            temp = new value_type[rsize];
            for (auto i = 0; i < size_; i++)
            {
                temp[i] = Data_[i];
            }
            for (auto i = size_; i < capacity_; i++)
            {
                temp[i] = value_type();
            }
            size_ = rsize;
            delete [] Data_;
            Data_ = temp;
            temp = nullptr;

        }
    }
    
Resize funkcija perkopijuoja senus **Vector** narius i nauja kitokio dydzio **Vector** ir po to priskiria juos prie seno **Vector** pointeriu bei istrina sena **Vector**

    iterator erase(iterator pointer)
    {
        size_type del;
        for (size_type i = 0; i < size_; ++i)
        {
            if (&Data_[i] == pointer)
                del = i;


        }
        for (size_type i = del; i < size_; i++)
        {
            Data_[i] = Data_[i + 1];
        }
        Data_[size_].~value_type();
        size_ = size_ - 1;
        return &Data_[del];
    }
    
Iterator erase funkcija istrina nari i kuri yra paduodamas pointeris , o tada perstumia visus tolimesnius narius viena vieta atgal

    void reserve(size_type rcapacity)
    {
        if (capacity_ < rcapacity)
        {
            capacity_ = rcapacity;
            value_type *temp = new value_type[capacity_];

            for (auto i = 0; i < size_; i++)
            {
                temp[i] = Data_[i];
            }
            delete[] Data_;
            Data_ = temp;
            temp = nullptr;
        }
    }
    
Reserve funkcija isskiria vietos atmintyje sukurdama reikiamo dydzio objekta. Tuomet perkopijuojamos senos reiksmes ir jos istrinamos, po to naujas masyvas prisikiriamas senam pointeriui

    void push_back(const_reference value)
    {
        if (capacity_ == 0)
        {
            capacity_++;
            size_++;
            Data_ = new value_type[size_];
            Data_[0] = value;
        }
        else
        {
            if (size_ >= capacity_)
                reserve(capacity_ * 2);
            Data_[size_++] = value;
        }
    }
    
Push_back funkcija ideda paduota reiksme i **Vector** gala ir padidina jo dydi vienu.

    void shrink_to_fit()
    {
        if (capacity_ > size_)
        {
            value_type *temp = new value_type[size_];
            for (auto i = 0; i < size_; i++)
            {
                temp[i] = Data_[i];
            }
            delete[] Data_;
            Data_ = temp;
            temp = nullptr;
            capacity_ = size_;
        }
    }
    
Shrink_to_fit sumazina capacity iki size, jeigu capacity yra didesnis uz size.

# Laiko matavimas

Push_back()

| Kontaineris | Talpa | Laikas |
|--|--|--|
| std::vector | 1000000 | 0.021941 s |
| vector | 1000000 | 0.010017 s |
| std::vector | 10000000 |  0.224834 s |
| vector | 10000000 | 0.132645 s |
| std::vector | 100000000 |  2.19893 s |
| vector | 10000000 | 1.17731 s |

Capacity count

| Kontaineris | Talpa | capacity()==size() kartai |
|--|--|--|
| std::vector | 1000000 | 21 |
| vector | 100000 | 21 |
| std::vector | 10000000 | 25 |
| vector | 1000000 | 25 |
| std::vector | 100000000 | 28 |
| vector | 10000000 | 28 |
