// Room: /d/feiyu/miaopu6.c

inherit __DIR__"miaopu";

void create()
{
	set("short", "��ҩ����[6]");
	set("long", @LONG
����������������ҩ�����ԣ�����Ϊ���»���Ӱ�죬ÿһ
�����Զ���ľ�����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"miaopu5",
  "south" : __DIR__"miaopu7",
  "north" : __DIR__"miaopu1",
]));

	set("outdoors","feiyu");
	setup();
}
