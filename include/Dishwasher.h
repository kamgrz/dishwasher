#ifndef DISHWASHER_H
#define DISHWASHER_H

class Dishwasher
{
    public:
        Dishwasher();
        virtual ~Dishwasher();
        void start();
        bool stop();
        void pause();

    protected:

    private:
};

#endif // DISHWASHER_H
