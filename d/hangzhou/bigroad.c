// Room: /d/hangzhou/bigroad.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
�������ں��ݸ��Ĺٵ��ϣ��������ϾͿ��Ե��ﺼ�ݸ�����
���ţ�����������Ǻ��ݵ����棬��˸���ĸɾ����ֵ��Ķ���
�Ǻ�����ջ��
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"southdoor",
  "east" : __DIR__"business",
  "north" : __DIR__"guotaie3",
]));


        set("objects",([
        NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
