// /d/changan/whroad3  ����·

inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
����ĳ����ǵ�����·���ǳ������������ֵ�֮һ��������
�ڽ��ڻʹ�������ʱʱ���䱸ɭ�ϣ�һ���ϰ��ն���Ը�����
������Ǿ�ʦ���ŵ����ڵأ����Ÿ�ʽ�ٷ����˳����������Ա�
��ǽͣ��һ�ŹٽΣ��η�����һ��˵Ц���졣
LONG
        );

	set("exits", ([
		"west"		   : __DIR__"yamen",
                "north"            : __DIR__"whroad2",
                "south"            : __DIR__"whroad4",
]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}