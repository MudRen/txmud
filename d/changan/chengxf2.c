// Room: chengxf2.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����ǳ���ة�ฮ���������������ڼ���Сˮ���ϵ�������
���ϣ�Сˮ�������Ǻɻ��������������������ĺ��㣬������
��ʼ�����Լ��ǲ������Ϸ������¾����ĵأ�ż������������ʹ
����о����ǰ��ݡ�
LONG
	);

        set("exits", ([
  "south" : __DIR__"chengxf3",
  "west" : __DIR__"chengxf1",
]));
        set("outdoors","chengxf");
        setup();

	replace_program(ROOM);
}