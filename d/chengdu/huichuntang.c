// Room: /wiz/louth/c/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "�ش���");
	set("long", @LONG
����������ȫ�������������Ļش���ҩ�ꡣ����������ζ��
����ҩ������ζ����΢������ҽ�����������������������Ρ�
���Ρ����ʪ��ǿ��ǵ����á���Ϊ�����ǻش��ö��еģ�ÿ��
���д���ҩ�ķ������ι�Ҫ�����������������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wwdao1",
]));
        set("objects",([
        __DIR__"npc/longboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
