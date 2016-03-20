int n = 0;
FILE *f = fopen("task.txt", "r");
Node *cur_to_del = NULL;
fscanf(f, "%"SCNi32, &n);
struct Data *p = (struct Data  *)malloc(n*sizeof(struct Data));
for (size_t i = 0; i < n; i++){
	fscanf(f, "%"SCNi32" %"SCNi32" %"SCNi32" %"SCNi32, &p[i].left_x, &p[i].left_y, &p[i].right_x, &p[i].right_y);
}
qsort(p, n, sizeof(struct Data), CompareData);
for (size_t i = 0; i < n; i++){
	insertNode(p[i]);
	cur_to_del = findNodeLt(root, p[i]);
	while (cur_to_del != NIL && cur_to_del){
		deleteNode(cur_to_del);
		count++;
		cur_to_del = findNodeLt(root, p[i]);
	}
}
while (root != NIL && root){
	deleteNode(root);
	count++;
}
printf("%"PRIi32, count);
system("pause");
return 0;



int n = 0;
Node *cur_to_del = NULL;
scanf("%"SCNi32, &n);
struct Data *p = (struct Data  *)malloc(n*sizeof(struct Data));
for (size_t i = 0; i < n; i++){
	scanf("%"SCNi32" %"SCNi32" %"SCNi32" %"SCNi32, &p[i].left_x, &p[i].left_y, &p[i].right_x, &p[i].right_y);
}
qsort(p, n, sizeof(struct Data), CompareData);
for (size_t i = 0; i < n; i++){
	insertNode(p[i]);
	cur_to_del = findNodeLt(p[i]);
	while (cur_to_del != NIL && cur_to_del){
		deleteNode(cur_to_del);
		count++;
		cur_to_del = findNodeLt(p[i]);
	}
}
while (root != NIL && root){
	deleteNode(root);
	count++;
}
printf("%"PRIi32, count);
system("pause");
return 0;