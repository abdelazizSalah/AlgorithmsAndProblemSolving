# UNQ_C2
# GRADED FUNCTION: compute_centroids
import numpy as np
import pandas as pd


def compute_centroids(X, idx, K):
    """
    Returns the new centroids by computing the means of the 
    data points assigned to each centroid.

    Args:
        X (ndarray):   (m, n) Data points
        idx (ndarray): (m,) Array containing index of closest centroid for each 
                       example in X. Concretely, idx[i] contains the index of 
                       the centroid closest to example i
        K (int):       number of centroids

    Returns:
        centroids (ndarray): (K, n) New centroids computed
    """

    # Useful variables
    m, n = X.shape

    # You need to return the following variables correctly
    centroids = np.zeros((K, n))

    ### START CODE HERE ###
    series = pd.Series({'cluster': idx})
    print(
        series.groupby('cluster').mean()
    )

    ### END CODE HERE ##

    return centroids


np.mean()

X = np.array([
    [20, 30],
    [10, 30],
    [10, 10],
])

idx = [1, 1, 0]

k = 2
print(compute_centroids(X, idx, k))
