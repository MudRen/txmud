// Room: /wiz/louth/c/fangjvdian.c

inherit ROOM;

void create()
{
	set("short", "���ߵ�");
	set("long", @LONG
�����ǳɶ��ķ��ߵꡣ���ڰڷţ��Ź��Ÿ�ʽ�����Ļ��ߡ�
���ߵ��ϰ���Ц���еĵ�����ĵ�����������ž�����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao1",
]));
        set("objects",([
        __DIR__"npc/jinboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
