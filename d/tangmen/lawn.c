// Room: /d/tangmen/lawn.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ����Ĳݵأ�����ϡϡ����ĳ��ż���������
Χ�Ŀ�����ɢ���ŵ����Ĳ�ҩ��ζ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaoyuan",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
