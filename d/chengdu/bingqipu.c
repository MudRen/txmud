// Room: /wiz/louth/c/bingqipu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ܴ�ķ��ӣ�������ڷ��Ÿ�ʽ�����ı���������
�˻�����ϸ����ѡ��һ������ٸ���������ʲô��������������
һ�������������ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao4",
]));
        set("objects",([
                __DIR__"npc/songboss" :1,        
        ]));

	setup();
	replace_program(ROOM);
}
