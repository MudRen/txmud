// Room: /d/fengtian/kd9.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����·�ľ�ͷ��С���Ǹ�������������бб��С���խ����
�����ˣ���������ס�����в��ٺ�������·����ˣ������ʱ��С
�������լ��Ͳ��Ʈ���˴��̡�
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"fangjia",
  "southeast" : __DIR__"kd8",
]));

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	setup();
	replace_program(ROOM);
}
