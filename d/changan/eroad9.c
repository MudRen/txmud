// /d/changan/eroad9 �������

inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
�����ǳ����ǵĶ��������������ȥ�ʹ���Ψһ����������
��������ĳ��ޣ�ÿ�쵽δʱ���ͻ������ĳ�����¡¡���ɴ�
����������ס������İ����ƺ������Ǽ��ֲ����ˡ�����������
�ڻ���·�Ķ���·����ֱͨ�����ǵĶ��š�
LONG
        );

	set("exits", ([
                "east"           : __DIR__"eroad4",
                "west"           : __DIR__"ehroad2",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
