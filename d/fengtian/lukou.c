// Room: /d/fengtian/lukou.c

inherit ROOM;

void create()
{
	set("short", "·��");
	set("long", @LONG
������һ��СС��·�ڣ����ڿ�����������ţ�����������
���ϣ����Ƿǳ������֣����Ͽ����츮������ңң����������һ
ֱ�߾��Ƿ�������ĵش��ˡ�
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"kd5",
  "south" : __DIR__"guanlu2",
  "east" : __DIR__"kd4",
  "north" : __DIR__"xm1",
]));

	setup();
	replace_program(ROOM);
}
