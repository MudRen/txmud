// Room: /u/w/wangs/b/kai151.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʱ����������ʱ�򣬳������������ڣ�ֻ����������
�������ߺ����������������һ���ҵ�һ����Ϳ���ô��һ
�������������ĳ���Լ����ʮ�������ڳ�����̫�ȵĹ�ϵ����
����һ����������������Χ�ײ�һ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai149",
]));

	setup();
	replace_program(ROOM);
}
