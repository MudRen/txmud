// Room: /d/fengtian/ll2.c

inherit ROOM;

void create()
{
	set("short", "���ֽ�");
	set("long", @LONG
���ֽ��Ƿ����һ�������ֵ����������ų����Ĳ�������
�Լ�������İ�������Ҳ�𽥷����������𽥳�Ϊ�����һ����
Ҫ��ҵ���ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ll3",
  "east" : __DIR__"mu",
  "north" : __DIR__"ll1",
]));
        set("outdoors", "fengtian");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 3,
]));

	setup();
	replace_program(ROOM);
}
