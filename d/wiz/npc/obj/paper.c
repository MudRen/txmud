// paper.c
// Find

inherit ITEM;

protected string content = "[1;37m
         欢迎新居民 - %s

    欢迎来到《天下》定居，《天下》的网上家园在地
址是：
           [1;32mhttp://www.mud-fl.com[1;37m
那里是居民们经常要去转转的地方，有什么天下大事都
会在那里公布，如果是新住户，一定要花几分钟去那里
看看，会有不少收获。

    来到一个新环境，会遇到很多的挑战需要你去一一
应付解决，有什么不懂得地方，多找老住户问问。

    现在开始吧，靠自己的双手，描绘灿烂的人生。

    相信：[47m[1;31m天[1;35m下[1;32m有[1;33m你[1;36m会[1;34m更[1;37m精彩。。。
[2;37;0m
";


protected string this_long = "\n欢迎 %s 入住天下，请用 read book 命令
仔细阅读入住手册。\n";

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
	set("name", sprintf("%s的入住手册", name));
}

void create()
{
	set_name("书", ({ "book" }) );
	set("unit", "册");
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
		return notify_fail("你要读什么？\n");

	write(content);

	me->set_temp("read_book",1);

	shi = present("dayuan xianshi",environment(me));
	if(shi)
		shi->can_enter(me);
	return 1;
}
