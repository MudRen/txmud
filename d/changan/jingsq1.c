// jingsq1  ��ˮ��

inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
������ͨ���ʹ��Ľ�ˮ�ţ����ߵĺ��������˾���ϸ����һ
���޴󻪱����ڲ�Զ�ĵط����ഫ����Ļ����Ǵ󳼻����д��
���ϵ������õģ����ֳơ��̰�ľ����������Ȼ���ڲ���������
д�һ��ˡ�������Ϳ��Կ����޴�Ĺ��š��������ţ������
������ˮ���е����ĵ�ˮ�������������������ϻ�·ֱͨ������
�ţ������ǻʹ��ˡ�
LONG
        );

	set("exits", ([
		"south" : __DIR__"shroad2",
		"north" : "/d/huanggong/nanm",
]) );

	set("outdoors","changan");
	set("cannot_build_home",1);
	setup();
	replace_program(ROOM);
}