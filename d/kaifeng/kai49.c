// Room: /u/w/wangs/b/kai49.c

inherit ROOM;

void create()
{
	set("short", "�鱦��");
	set("long", @LONG
����·�Ͼ�Ȼ�����鱦�꣬�����һ���ɻ�ı������˽�����
�����˰����������´�����һ�飬������������Цӭ����������
ͷ�����Ĵ���ȥѡ�����Ρ���ӹ�̨�ϵ�̴ľϻ����������һ��
������������ӭ�Ź�һ����������ȻʧЦ��ԭ���������Ķ��Ǳ�
�˵ļٻ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai61",
]));
        set("objects",([
        __DIR__"npc/qianlaoban" : 1,
]));

	setup();
	replace_program(ROOM);
}
