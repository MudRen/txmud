// Room: /u/w/wangs/a/yu85.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������˽�˷��䣬���ϱ�������������룬
����Ҳ��һ����Ⱦ������ôððʧʧ�Ĵ��˽����ƺ���Щ��
̫��ò��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yu84",
]));
        set("objects", ([
        __DIR__"npc/xue": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
