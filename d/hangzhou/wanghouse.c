// Room: /d/hangzhou/wanghouse.c

inherit ROOM;

void create()
{
	set("short", "���Ϻ���");
	set("long", @LONG
����һ�������Ժ�ӣ�����Χ�����ǽ����ǽ��֧��һ����
�����Աߵļ��������������Ϻ��Ժ���������������һ��ʯ��
������ʯ�ʣ������ϻ��ڸ�һ���ƺ�«��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rockroad1",
]));

	setup();
	replace_program(ROOM);
}
