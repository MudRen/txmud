// Room: /open/dt/huayanlu2.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������Ĵ�֣�·���ɨ�øɸɾ����������ֵ��Ǵ�
ͬ������ÿ���Ľֵ�֮һ����Ȼ����û��ʲô��ĵ��̣�������
Ϊ�Ϸ��������˴��㼯���������ϣ����Ժܶ��̷����ڻ���·
�����˺ܶ��̯������һ������������һ����ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu1",
  "east" : __DIR__"huayanlu3",
  "south" : __DIR__"minju3",
  "north" : __DIR__"mafang",
]));

	set("outdoors","datong");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 2,
]));

	setup();
	replace_program(ROOM);
}
