// jingsq2  ��ˮ�Ŷ�

inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
�����ǵĽ�ˮ�ţ�����������˿�������ͼ������Զ����һ
������߸ߵĴ������Ƕ�������վ�Ų��ٽ�׵���ʿ�������ǻ�
���ĺ��ţ����Կ������ϾžŰ�ʮһ�Ž𶤡���ϡ�����������
ˮ�ӵ�ˮ��������������ò�Ҫ���������ɴ������ǻʹ�����
�Ǳ���·ֱͨ�����ǵı��š�
LONG
        );

	set("exits", ([
		"north" : __DIR__"nhroad2",
		"south" : "/d/huanggong/beim",
]) );
	set("outdoors","changan");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}