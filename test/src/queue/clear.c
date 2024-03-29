START_TEST(clear_ok)
{
	struct sp_queue *s;
	ck_assert_ptr_nonnull(s = sp_queue_create(sizeof(int), 30));
	ck_assert_int_eq(0, sp_queue_pushi(s, 1));
	ck_assert_int_eq(0, sp_queue_pushi(s, 2));
	ck_assert_int_eq(0, sp_queue_pushi(s, 3));
	ck_assert_int_eq(0, sp_queue_clear(s, NULL));
	ck_assert_uint_eq(0, s->size);
	ck_assert_int_eq(0, sp_queue_destroy(s, NULL));
}
END_TEST

START_TEST(clear_object)
{
	struct sp_queue *s;
	struct data a, b, c;
	data_init(&a);
	data_init(&b);
	data_init(&c);
	ck_assert_ptr_nonnull(s = sp_queue_create(sizeof(struct data), 5));
	ck_assert_int_eq(0, sp_queue_push(s, &a));
	ck_assert_int_eq(0, sp_queue_push(s, &b));
	ck_assert_int_eq(0, sp_queue_push(s, &c));
	ck_assert_int_eq(0, sp_queue_clear(s, data_dtor));
	ck_assert_uint_eq(0, s->size);
	ck_assert_int_eq(0, sp_queue_destroy(s, NULL));
}
END_TEST

START_TEST(clear_bad_args)
{
	ck_assert_int_eq(SP_EINVAL, sp_queue_clear(NULL, NULL));
	ck_assert_int_eq(SP_EINVAL, sp_queue_clear(NULL, data_dtor));
}
END_TEST

START_TEST(clear_bad_dtor)
{
	struct sp_queue *s;
	struct data a;
	data_init(&a);
	ck_assert_ptr_nonnull(s = sp_queue_create(sizeof(struct data), 10));
	ck_assert_int_eq(0, sp_queue_push(s, &a));
	ck_assert_int_eq(SP_ECALLBK, sp_queue_clear(s, data_dtor_bad));
	ck_assert_int_eq(0, sp_queue_clear(s, NULL));
	ck_assert_int_eq(0, sp_queue_destroy(s, NULL));
	data_dtor(&a);
}
END_TEST


void init_clear(Suite *suite, TCase *tc)
{
	suite_add_tcase(suite, tc);
	tcase_add_test(tc, clear_ok);
	tcase_add_test(tc, clear_object);
	tcase_add_test(tc, clear_bad_args);
	tcase_add_test(tc, clear_bad_dtor);
}
