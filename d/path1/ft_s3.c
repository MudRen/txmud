// Room: /d/path1/ft_s3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ɽ��С·��·�������ǴԴԵ��������롣��������
ϡ�٣�̧����ȥ����ͺͺ��ɽ��͸��һ˿˿���⣬�㲻�ɵüӿ�
�˽Ų���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ft_s4",
  "northwest" : __DIR__"ft_s2",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
