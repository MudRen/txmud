// Room: /d/changan/sroad7.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ﳤ���ǵ��ϴ�ֵĶ��ߵش��������������˲��٣�����
����ɫ�Ҵҡ������Ǿ������������У�Ҳ���ڵ�����ļ�ɢ�أ�
���ص����Ӷ��㼯������н��ס����ص����ӣ����������
�Լ�����ƥ����ʱ����һ�������˻�С�
LONG
	);

	set("outdoors", "changan");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/cleaner" : 1,
]));

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sroad6",
  "south" : __DIR__"mashi",
  "east" : __DIR__"sroad8",
]));

	set("objects",([
	NPC_DIR"xunpu" : 2,
	NPC_DIR"stdnpc/stdnpc_3" : 2,
]));
	setup();
	replace_program(ROOM);
}
