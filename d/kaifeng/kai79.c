// Room: /wiz/louth/k/kai79.c

inherit ROOM;

void create()
{
	set("short", "�����¥");
	set("long", @LONG
��¥����ƻ�ͨ��������ǳ��ã�����������ϯ���������
���������ȱ�������Ļ��á����ۣ��ر�Ƹ�����Ĵ��ʦ������
��һζ����ʨ��ͷ��Ҳ������Ⱥ��ݡ���Ԫ�ꡱС��Ƥ��������
������������޵����ѿͣ�������ҲӦ�ÿ���һ������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"kai38",
  "west" : __DIR__"kai77",
  "south" : __DIR__"kai76",
]));

        set("objects",([
        __DIR__"npc/xiaoer" : 1,
]));
        set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
