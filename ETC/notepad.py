import numpy as np




if __name__ == '__main__':
    X = 2 * np.random.rand(3, 1)
    print(X)
    print(np.ones((3,1)))
    print(np.c_[np.ones((3,1)), X])


