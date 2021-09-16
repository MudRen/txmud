// paper.c
// Find

inherit ITEM;

protected string content = "[1;37m
         »¶Ó­ĞÂ¾ÓÃñ - %s

    »¶Ó­À´µ½¡¶ÌìÏÂ¡·¶¨¾Ó£¬¡¶ÌìÏÂ¡·µÄÍøÉÏ¼ÒÔ°ÔÚµØ
Ö·ÊÇ£º
           [1;32mhttp://www.mud-fl.com[1;37m
ÄÇÀïÊÇ¾ÓÃñÃÇ¾­³£ÒªÈ¥×ª×ªµÄµØ·½£¬ÓĞÊ²Ã´ÌìÏÂ´óÊÂ¶¼
»áÔÚÄÇÀï¹«²¼£¬Èç¹ûÊÇĞÂ×¡»§£¬Ò»¶¨Òª»¨¼¸·ÖÖÓÈ¥ÄÇÀï
¿´¿´£¬»áÓĞ²»ÉÙÊÕ»ñ¡£

    À´µ½Ò»¸öĞÂ»·¾³£¬»áÓöµ½ºÜ¶àµÄÌôÕ½ĞèÒªÄãÈ¥Ò»Ò»
Ó¦¸¶½â¾ö£¬ÓĞÊ²Ã´²»¶®µÃµØ·½£¬¶àÕÒÀÏ×¡»§ÎÊÎÊ¡£

    ÏÖÔÚ¿ªÊ¼°É£¬¿¿×Ô¼ºµÄË«ÊÖ£¬Ãè»æ²ÓÀÃµÄÈËÉú¡£

    ÏàĞÅ£º[47m[1;31mÌì[1;35mÏÂ[1;32mÓĞ[1;33mÄã[1;36m»á[1;34m¸ü[1;37m¾«²Ê¡£¡£¡£
[2;37;0m
";


protected string this_long = "\n»¶Ó­ %s Èë×¡ÌìÏÂ£¬ÇëÓÃ read book ÃüÁî
×ĞÏ¸ÔÄ¶ÁÈë×¡ÊÖ²á¡£\n";

protected string query_long()
{
	return this_long;
}

void set_owner(string name)
{
	if(!stringp(name) || !sizeof(name))
		return;

	this_long = sprintf(this_long, name);
	content = sprintf(content, name);
	set("name", sprintf("%sµÄÈë×¡ÊÖ²á", name));
}

void create()
{
	set_name("Êé", ({ "book" }) );
	set("unit", "²á");
	set("long",(: query_long :));
	set_weight(50);
	setup();
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
	object shi,me = this_player();

	if(arg != "book")
		return notify_fail("ÄãÒª¶ÁÊ²Ã´£¿\n");

	write(content);

	me->set_temp("read_book",1);

	shi = present("dayuan xianshi",environment(me));
	if(shi)
		shi->can_enter(me);
	return 1;
}
