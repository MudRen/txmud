// shroad1  �ϻ�·

inherit ROOM;

void create()
{
        set("short", "�ϻ�·");
        set("long", @LONG
�����ǳ����ǵ��ϻ�·���ǳ����������ֵ�֮һ�������ǽ�
�ڻʳǵ��ڻ�·�����Խ䱸ɭ�ϣ�Ѳ�������־��������ϣ�һ��
�ϰ��ն�������������Ե÷ǳ��徻������ߴ�Ĺ�ǽ��ʾ��
�ޱȵĻ���������ǧ������Ȩ����������������ɵõ���ɮ����
����ס�ֵĻʼ���Ժ�����¡�
LONG
        );

	set("exits", ([
		"south"		   : __DIR__"baoxiang",
                "west"             : __DIR__"whroad4",
                "east"             : __DIR__"shroad2",
 ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
