// /d/changan/wroad9  �������

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
�����ǳ����ǵ��������������ֱͨ�ʳǵ����ţ������ʹ�
��������ˮ��ˮ����ÿ���гɳ���Ȫˮ�������˽��ʹ�����ʱ��
Ѻˮ�Ĺ�Ա���ߺ��š��رܡ�����������ֱͨ�����ǵ����ţ���
���ǳ������ڻ���·������·��
LONG
        );

	set("exits", ([
		"west"             : __DIR__"wroad4",
		"east"             : __DIR__"whroad2", ]) );

	set("outdoors","changan");

	set("objects",([
	__DIR__"npc/shusheng" : 1,
]));

	setup();
	replace_program(ROOM);
}
