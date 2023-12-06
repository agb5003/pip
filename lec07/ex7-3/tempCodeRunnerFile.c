void print_person(int i, st_person *pointer_member) {
    printf("%d. Name = %s\n", i+1, pointer_member->name);
    printf("   Height = %.2f\n", pointer_member->height);
    printf("   Weight = %.2f\n", pointer_member->weight);
}
