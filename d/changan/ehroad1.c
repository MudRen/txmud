// ehroad1  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ǳ����ǵĶ���·���ǳ����������ֵ�֮һ�������ǽ�
�ڻʳǵ��ڻ�·�����Խ䱸ɭ�ϣ�Ѳ�������־��������ϣ�һ��
�ϰ��ն�������������Ե÷ǳ��徻������ߴ�Ĺ�ǽ��ʾ��
�ޱȵĻ���������ǧ������Ȩ������������������̸�
LONG
        );

	set("exits", ([
		"east"		   : __DIR__"ly-ge",
                "south"            : __DIR__"shroad4",
                "north"            : __DIR__"ehroad2",
]) );
	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
