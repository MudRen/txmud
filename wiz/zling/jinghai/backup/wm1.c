// Room: /d/jinghai/wm1.c

inherit ROOM;

void create()
{
	set("short", "����������ͷ");
	set("long", @LONG
�˴�����һ����ͷ�������ˮ��ǳ����������ͷ�������н�
��ĵط�бб������һ��ջ�ţ�ջ�ž�ͷ�������ͣ����һ��С
������ͷ�ߵĸ��������϶���һ��ľ�壬����д�ţ���������ר
����ͷ����
LONG
	);
	set("outdoors", "jinghai");
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"wm11",
]));

	setup();
	replace_program(ROOM);
}
