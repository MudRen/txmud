// Room: /wiz/louth/c/wuguan.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����ǳɶ����Ĵ�����ݡ����ڵĽ�ͷ�͵��Ӳ�����ʮ�ˣ�
ÿ�춼�ܿ�����ݵ�����������ϰ�书��������������������
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao2",
]));
        set("objects",([
                __DIR__"npc/jiaotou" :1,        
        ]));

	setup();
	replace_program(ROOM);
}
