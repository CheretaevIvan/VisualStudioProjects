#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct {
	int32_t data, number;
}Player;

typedef Player item_type;

typedef enum sort_order {
	ASCENDING,
	DESCENDING
} sort_order;

void swap(item_type *arr, unsigned int a, unsigned int b) {
	if (a == b) return;
	item_type tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void heapify(item_type *arr, unsigned int n, unsigned int index, sort_order order) {
	if (index >= n) return;
	unsigned int min_max = index;
	unsigned int left = index * 2 + 1;
	unsigned int right = index * 2 + 2;

	if (left < n && (order == DESCENDING ? arr[min_max].data > arr[left].data : arr[min_max].data < arr[left].data)) min_max = left;
	if (right < n && (order == DESCENDING ? arr[min_max].data > arr[right].data : arr[min_max].data < arr[right].data)) min_max = right;
	if (min_max != index) {
		swap(arr, index, min_max);
		heapify(arr, n, min_max, order);
	}
}

void make_heap(item_type *arr, unsigned int n, sort_order order) {
	if (n <= 1) return;
	int i;
	for (i = (n - 2) / 2; i >= 0; i--) heapify(arr, n, i, order);
}

void heap_sort(item_type *arr, unsigned int n, sort_order order) {
	unsigned int i;
	make_heap(arr, n, order);
	for (i = 0; i < n - 1; i++) {
		swap(arr, 0, n - 1 - i);
		heapify(arr, n - i - 1, 0, order);
	}
}

int main()
{
	size_t number_of_players = 0;
	scanf("%"SCNi32, &number_of_players);
	Player *players = (Player*)calloc(number_of_players, sizeof(Player));//удалить (int*)
	if (!players)
		return 1;
	for (size_t i = 0; i < number_of_players; ++i)// использовать size_t для индексации
	{
		players[i].number = i + 1;
		scanf("%"SCNi32, &players[i].data);
	}
	heap_sort(players, number_of_players, ASCENDING);

	int i = 0, j = 1;
	int boss_player = i;
	int less_player = i;
	int64_t cur_command = players[0].data;
	int64_t max_command = cur_command;
	while (j < number_of_players){
		if (players[j].data <= (players[i].data + players[i + 1].data)){
			cur_command += players[j].data;
			if (cur_command > max_command){
				less_player = i;
				boss_player = j;
				max_command = cur_command;
			}
			j++;
		}
		else{
			cur_command -= players[i].data;
			i++;
		}
	}
	printf("%"PRIi64"\n", max_command);
	Player *sort_player_command = (Player*)calloc(boss_player - less_player + 1, sizeof(Player));
	for (size_t i = less_player, count = 0; i <= boss_player; i++, count++)
		sort_player_command[count].data = players[i].number;
	heap_sort(sort_player_command, boss_player - less_player + 1, ASCENDING);
	for (size_t i = 0; i < boss_player - less_player + 1; i++)
		printf("%"PRIi32"%c", sort_player_command[i].data, (i != boss_player - less_player) ? ' ' : '\n');
	system("pause");
	return 0;
}