// Room: /d/shaolin/gulou4.c

inherit ROOM;

void create()
{
	set("short", "��¥�Ĳ�");
	set("long", @LONG
�����������µĹ�¥�Ĳ㣬һ��¥�������ȿ��Կ���һ����
������ģ����Ѿ�����ĺܶ��ˣ��Ա�һ���ܴ�����ʹĴ�����
˵Ҳ�ж�ʮ����أ�����ʮ�������������û�ж�������������
���ǹ�¥���㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"gulou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
