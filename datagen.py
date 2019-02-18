from cyaron import *

_n = ati([0, 1, 7, 7, 10, 10, 100, 300, 500, 1000, 2000,
          1E4, 2E4, 3E4, 5E4, 1E5, 1E5, 1E5, 1E5, 1E5, 1E5])

mx = ati([2E9])[0]

for i in range(1, 21):
    test_data = IO(file_prefix="", data_id=i)

    n = _n[i]

    test_data.input_writeln(n)

    if i == 1:
        test_data.input_writeln(233)
    elif i == 2:
        test_data.input_writeln(1, 2, 3, 4, 5, 6, 7)
        test_data.input_writeln(1, 2)
        test_data.input_writeln(1, 3)
        test_data.input_writeln(2, 4)
        test_data.input_writeln(2, 5)
        test_data.input_writeln(3, 6)
        test_data.input_writeln(3, 7)
    elif i == 3:
        test_data.input_writeln(1, 2, 3, 4, 5, 6, 7)
        test_data.input_writeln(1, 2)
        test_data.input_writeln(2, 3)
        test_data.input_writeln(3, 4)
        test_data.input_writeln(4, 5)
        test_data.input_writeln(5, 6)
        test_data.input_writeln(6, 7)
    elif i <= 17:
        for i in range(n):
            test_data.input_write(randint(1, mx))
        test_data.input_writeln()

        tree = Graph.tree(n, directed=True)
    elif i == 18:
        for i in range(n):
            test_data.input_write(mx)
        test_data.input_writeln()

        tree = Graph.tree(n, directed=True)
    elif i == 19:
        for i in range(n):
            test_data.input_write(mx)
        test_data.input_writeln()

        tree = Graph.tree(n, 0.4, 0.35, directed=True)
    else:
        for i in range(n):
            test_data.input_write(mx)
        test_data.input_writeln()

        tree = Graph.tree(n, 0.0, 1.0, directed=True)
    if i >= 4:
        for edges in tree.edges:
            for edge in edges:
                test_data.input_writeln(edge.start, edge.end)
    test_data.output_gen("./a")



