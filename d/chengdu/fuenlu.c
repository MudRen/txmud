// Room: /wiz/louth/c/fuenlu.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��Ƨ������ש·��·��ͣ�ż���С�Σ������η��ڵ�
��˵Ц�ţ����������ǳɶ����õ����ڵأ��ϰ���û���Ǿ�����
������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xunbufang",
  "south" : __DIR__"yamen",
  "north" : __DIR__"shizi1",
]));

	setup();
	replace_program(ROOM);
}
