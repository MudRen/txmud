// Room: /u/w/wangs/a/yu4.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ��ͷ�����ǽ����һ����ľ�󴲣�����ı��쾡
�����壬�������ס����з���һ�Ű����������ϰ���Щ��Ʒ��
ʹ�˴������Ρ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yu2",
]));

        set("objects", ([
        __DIR__"npc/han": 1,
                        ]) );
	setup();
	replace_program(ROOM);
}
