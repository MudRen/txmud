// Room: /d/shaolin/jielv.c

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
������������������½���Ժ�����������ִ����Ϊ�ϸ�
һ��������Υ�����ɵ�ɮ�ˣ���������˽���顣�ϱ���һ���̼ܣ�
�ǶԷ�ɮִ�������õġ���������������ʯ�ݣ�����������ʯ
����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yongdao3",
  "west" : __DIR__"shiwu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
