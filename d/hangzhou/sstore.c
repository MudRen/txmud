// Room: /d/hangzhou/sstore.c

inherit ROOM;
// string look_sign(object me);

void create()
{
	set("short", "С��");
	set("long", @LONG
���������ں��ݳ��������һ��С�ꡣС���������һ����
�����ˣ������ڹ�̨��֯�Ŷ������������������̧ͷ����ķ�
��עĿ���������˵�΢Ц����̨�߷���һ������(sigh)��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"spath2",
]));

	setup();
	replace_program(ROOM);
}
