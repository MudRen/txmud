// ehroad3  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ����ǵĶ���·���ǳ����������ֵ�֮һ�������ǽ�
�ڻʳǵ��ڻ�·�����Խ䱸ɭ�ϣ�Ѳ�������־��������ϡ�����
�ǻ������ţ�Ҳ�����ڲ���Ͱ�������ϢϢ��أ����ﵽ�Ǿ���
��һЩƽ����ճ��롣
LONG
        );
	set("exits", ([
		"east" : __DIR__"hubu",
		"south" : __DIR__"ehroad2",
		"north" : __DIR__"ehroad4",
]) );

	set("outdoors","changan");
	setup();
}
