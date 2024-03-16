#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(test_abs_normal) {
  ck_assert_ldouble_eq_tol(abs(12), s21_abs(12), 1e-6);
}
START_TEST(test_abs_negative) {
  ck_assert_ldouble_eq_tol(abs(-12), s21_abs(-12), 1e-6);
}
START_TEST(test_abs_zero) {
  ck_assert_ldouble_eq_tol(abs(0), s21_abs(0), 1e-6);
}

START_TEST(test_acos_normal) {
  ck_assert_ldouble_eq_tol(acos(1), s21_acos(1), 1e-6);
}
START_TEST(test_acos_negative) {
  ck_assert_ldouble_eq_tol(acos(-1), s21_acos(-1), 1e-6);
}
START_TEST(test_acos_zero) {
  ck_assert_ldouble_eq_tol(acos(0), s21_acos(0), 1e-6);
}
START_TEST(test_acos_nan_negative) {
  ck_assert_ldouble_nan(acos(-2));
  ck_assert_ldouble_nan(s21_acos(-2));
}
END_TEST
START_TEST(test_acos_nan_positive) {
  ck_assert_ldouble_nan(acos(2));
  ck_assert_ldouble_nan(s21_acos(2));
}
END_TEST

START_TEST(test_fabs_normal) {
  ck_assert_ldouble_eq_tol(fabs(12.12345), s21_fabs(12.12345), 1e-6);
}
END_TEST
START_TEST(test_fabs_zero) {
  ck_assert_ldouble_eq_tol(fabs(0.), s21_abs(0.), 1e-6);
}
END_TEST
START_TEST(test_fabs_negative) {
  ck_assert_ldouble_eq_tol(fabs(-12.12345), s21_fabs(-12.12345), 1e-6);
}
END_TEST

START_TEST(test_fmod_normal) {
  ck_assert_ldouble_eq_tol(fmod(12.12345, 3.2), s21_fmod(12.12345, 3.2), 1e-6);
}
END_TEST
START_TEST(test_fmod_negative) {
  ck_assert_ldouble_eq_tol(fmod(-12.12345, 3.2), s21_fmod(-12.12345, 3.2),
                           1e-6);
}
END_TEST
START_TEST(test_fmod_zero) { ck_assert_double_nan(s21_fmod(12.12345, 0)); }
END_TEST

START_TEST(test_floor_normal_1) {
  ck_assert_ldouble_eq_tol(floor(1212345), s21_floor(1212345), 1e-6);
}
START_TEST(test_floor_normal_2) {
  ck_assert_ldouble_eq_tol(floor(0.1), s21_floor(0.1), 1e-6);
}
END_TEST
START_TEST(test_floor_zero) {
  ck_assert_ldouble_eq_tol(floor(0), s21_floor(0), 1e-6);
}
END_TEST
START_TEST(test_floor_negative_1) {
  ck_assert_ldouble_eq_tol(floor(-2), s21_floor(-2), 1e-6);
}
END_TEST
START_TEST(test_floor_negative_2) {
  ck_assert_ldouble_eq_tol(floor(-0.12345), s21_floor(-0.12345), 1e-6);
}
END_TEST

START_TEST(test_ceil_normal_1) {
  ck_assert_ldouble_eq_tol(ceil(1212345), s21_ceil(1212345), 1e-6);
}
START_TEST(test_ceil_normal_2) {
  ck_assert_ldouble_eq_tol(ceil(0.1), s21_ceil(0.1), 1e-6);
}
END_TEST
START_TEST(test_ceil_zero) {
  ck_assert_ldouble_eq_tol(ceil(0), s21_ceil(0), 1e-6);
}
END_TEST
START_TEST(test_ceil_negative_1) {
  ck_assert_ldouble_eq_tol(ceil(-1212345), s21_ceil(-1212345), 1e-6);
}
END_TEST
START_TEST(test_ceil_negative_2) {
  ck_assert_ldouble_eq_tol(ceil(-0.12345), s21_ceil(-0.12345), 1e-6);
}
END_TEST

START_TEST(test_cos_zero) {
  ck_assert_ldouble_eq_tol(cos(0), s21_cos(0), 1e-6);
}
END_TEST
START_TEST(test_cos_normal_1) {
  ck_assert_ldouble_eq_tol(cos(1), s21_cos(1), 1e-6);
}
START_TEST(test_cos_normal_2) {
  ck_assert_ldouble_eq_tol(cos(56), s21_cos(56), 1e-6);
}
END_TEST
START_TEST(test_cos_negative) {
  ck_assert_ldouble_eq_tol(cos(-1), s21_cos(-1), 1e-6);
}
END_TEST

START_TEST(test_asin_one) {
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), 1e-6);
}
END_TEST
START_TEST(test_asin_zero) {
  ck_assert_ldouble_eq_tol(asin(0), s21_asin(0), 1e-6);
}
END_TEST
START_TEST(test_asin_negative) {
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), 1e-6);
}
END_TEST
START_TEST(test_asin_nan_negative) {
  ck_assert_ldouble_nan(asin(-2));
  ck_assert_ldouble_nan(s21_asin(-2));
}
END_TEST
START_TEST(test_asin_nan_positive) {
  ck_assert_ldouble_nan(asin(2));
  ck_assert_ldouble_nan(s21_asin(2));
}
END_TEST

START_TEST(test_atan_normal) {
  ck_assert_ldouble_eq_tol(atan(13), s21_atan(13), 1e-6);
}
END_TEST
START_TEST(test_atan_zero) {
  ck_assert_ldouble_eq_tol(atan(0.00000001), s21_atan(0.0000001), 1e-6);
}
END_TEST
START_TEST(test_atan_negative) {
  ck_assert_float_eq_tol(atan(-13), s21_atan(-13), 1e-6);
}
END_TEST

START_TEST(test_exp_normal) {
  ck_assert_ldouble_eq_tol(exp(22), s21_exp(22), 1e-6);
}
END_TEST
START_TEST(test_exp_zero) {
  ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), 1e-6);
}
END_TEST
START_TEST(test_exp_negative) {
  ck_assert_ldouble_eq_tol(exp(-0.23), s21_exp(-0.23), 1e-6);
}
END_TEST

START_TEST(test_log_normal) {
  ck_assert_ldouble_eq_tol(log(1.5), s21_log(1.5), 1e-6);
}
END_TEST
START_TEST(test_log_negative) { ck_assert_ldouble_nan(s21_log(-1.5)); }
END_TEST
START_TEST(test_log_zero) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(test_pow_normal) {
  ck_assert_ldouble_eq_tol(pow(2, 1.1), s21_pow(2, 1.1), 1e-6);
}
END_TEST
START_TEST(test_pow_negative) {
  ck_assert_ldouble_eq_tol(pow(-1.5, 5), s21_pow(-1.5, 5), 1e-6);
}
END_TEST
START_TEST(test_pow_zero_1) {
  ck_assert_ldouble_eq_tol(pow(0, 5), s21_pow(0, 5), 1e-6);
}
START_TEST(test_pow_zero_2) {
  ck_assert_ldouble_eq_tol(pow(0, 0), s21_pow(0, 0), 1e-6);
}
END_TEST
START_TEST(test_base_negative_exp_negative) {
  ck_assert_ldouble_nan(pow(-2, -1.5));
  ck_assert_ldouble_nan(s21_pow(-2, -1.5));
}
END_TEST
START_TEST(test_base_negative_exp_whole_negative) {
  ck_assert_ldouble_eq_tol(pow(-2, -4), s21_pow(-2, -4), 1e-6);
}
END_TEST
START_TEST(test_base_positive_exp_whole_negative) {
  ck_assert_ldouble_eq_tol(pow(2, -4), s21_pow(2, -4), 1e-6);
}
END_TEST

START_TEST(test_sin_normal_1) {
  ck_assert_ldouble_eq_tol(sin(1.5), s21_sin(1.5), 1e-6);
}
START_TEST(test_sin_normal_2) {
  ck_assert_ldouble_eq_tol(sin(-15), s21_sin(-15), 1e-6);
}
START_TEST(test_sin_normal_3) {
  ck_assert_ldouble_eq_tol(sin(15), s21_sin(15), 1e-6);
}
END_TEST
START_TEST(test_sin_negative) {
  ck_assert_ldouble_eq_tol(sin(-1.5), s21_sin(-1.5), 1e-6);
}
END_TEST
START_TEST(test_sin_zero) {
  ck_assert_ldouble_eq_tol(sin(0), s21_sin(0), 1e-6);
}
END_TEST

START_TEST(test_sqrt_normal) {
  ck_assert_ldouble_eq_tol(sqrt(1.5), s21_sqrt(1.5), 1e-6);
}
END_TEST
START_TEST(test_sqrt_negative) { ck_assert_double_nan(s21_sqrt(-1.5)); }
END_TEST
START_TEST(test_sqrt_zero) {
  ck_assert_ldouble_eq_tol(sqrt(0), s21_sqrt(0), 1e-6);
}
END_TEST

START_TEST(test_tan_normal_1) {
  ck_assert_ldouble_eq_tol(tan(1.5), s21_tan(1.5), 1e-6);
}
START_TEST(test_tan_normal_2) {
  ck_assert_ldouble_eq_tol(tan(15), s21_tan(15), 1e-6);
}
END_TEST
START_TEST(test_tan_negative_1) {
  ck_assert_ldouble_eq_tol(tan(-1.5), s21_tan(-1.5), 1e-6);
}
END_TEST
START_TEST(test_tan_negative_2) {
  ck_assert_ldouble_eq_tol(tan(-4.5), s21_tan(-4.5), 1e-6);
}
END_TEST
START_TEST(test_tan_zero) {
  ck_assert_ldouble_eq_tol(tan(0), s21_tan(0), 1e-6);
}
END_TEST

Suite *s21_fabs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_fabs");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_fabs_normal);
  tcase_add_test(tc_core, test_fabs_zero);
  tcase_add_test(tc_core, test_fabs_negative);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_fmod_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_fmod");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_fmod_normal);
  tcase_add_test(tc_core, test_fmod_negative);
  tcase_add_test(tc_core, test_fmod_zero);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_floor_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_floor");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_floor_normal_1);
  tcase_add_test(tc_core, test_floor_normal_2);
  tcase_add_test(tc_core, test_floor_zero);
  tcase_add_test(tc_core, test_floor_negative_1);
  tcase_add_test(tc_core, test_floor_negative_2);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_ceil_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_ceil");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_ceil_normal_1);
  tcase_add_test(tc_core, test_ceil_normal_2);
  tcase_add_test(tc_core, test_ceil_zero);
  tcase_add_test(tc_core, test_ceil_negative_1);
  tcase_add_test(tc_core, test_ceil_negative_2);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_cos_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_cos");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_cos_normal_1);
  tcase_add_test(tc_core, test_cos_normal_2);
  tcase_add_test(tc_core, test_cos_negative);
  tcase_add_test(tc_core, test_cos_zero);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_asin_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_asin");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_asin_one);
  tcase_add_test(tc_core, test_asin_zero);
  tcase_add_test(tc_core, test_asin_negative);
  tcase_add_test(tc_core, test_asin_nan_negative);
  tcase_add_test(tc_core, test_asin_nan_positive);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_abs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_abs");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_abs_normal);
  tcase_add_test(tc_core, test_abs_negative);
  tcase_add_test(tc_core, test_abs_zero);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_acos_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_acos");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_acos_normal);
  tcase_add_test(tc_core, test_acos_negative);
  tcase_add_test(tc_core, test_acos_zero);
  tcase_add_test(tc_core, test_acos_nan_negative);
  tcase_add_test(tc_core, test_acos_nan_positive);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_atan_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_atan");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_atan_normal);
  tcase_add_test(tc_core, test_atan_zero);
  tcase_add_test(tc_core, test_atan_negative);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_exp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_exp");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_exp_normal);
  tcase_add_test(tc_core, test_exp_negative);
  tcase_add_test(tc_core, test_exp_zero);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_log_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_log");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_log_normal);
  tcase_add_test(tc_core, test_log_zero);
  tcase_add_test(tc_core, test_log_negative);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_pow_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_pow");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_pow_normal);
  tcase_add_test(tc_core, test_pow_zero_1);
  tcase_add_test(tc_core, test_pow_zero_2);
  tcase_add_test(tc_core, test_pow_negative);
  tcase_add_test(tc_core, test_base_negative_exp_negative);
  tcase_add_test(tc_core, test_base_negative_exp_whole_negative);
  tcase_add_test(tc_core, test_base_positive_exp_whole_negative);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_sin_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_sin");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_sin_normal_1);
  tcase_add_test(tc_core, test_sin_normal_2);
  tcase_add_test(tc_core, test_sin_normal_3);
  tcase_add_test(tc_core, test_sin_zero);
  tcase_add_test(tc_core, test_sin_negative);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_sqrt_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_sqrt");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_sqrt_normal);
  tcase_add_test(tc_core, test_sqrt_zero);
  tcase_add_test(tc_core, test_sqrt_negative);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *s21_tan_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_tan");
  tc_core = tcase_create("all_in_one");
  tcase_add_test(tc_core, test_tan_normal_1);
  tcase_add_test(tc_core, test_tan_normal_2);
  tcase_add_test(tc_core, test_tan_zero);
  tcase_add_test(tc_core, test_tan_negative_1);
  tcase_add_test(tc_core, test_tan_negative_2);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;
  // abs testing
  s = s21_abs_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // acos testing
  s = s21_acos_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // asin testing
  s = s21_asin_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // atan testing
  s = s21_atan_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // ceil testing
  s = s21_ceil_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // cos testing
  s = s21_cos_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // exp testing
  s = s21_exp_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // fabs testing
  s = s21_fabs_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // floor testing
  s = s21_floor_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // fmod testing
  s = s21_fmod_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // log testing
  s = s21_log_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // pow testing
  s = s21_pow_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // sin testing
  s = s21_sin_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // sqrt testing
  s = s21_sqrt_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  // tan testing
  s = s21_tan_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

  return 0;
}
