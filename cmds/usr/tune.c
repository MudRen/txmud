// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *tuned_ch;

	tuned_ch = me->query("channels");

	if( !arg ) {
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("你现在并没有收听任何频道。\n");
		else
			write("你现在收听的频道：" + implode(tuned_ch, ", ") + "。\n");
		return 1;
	}

	if( (arg == "paimai") || (arg == "psell") ) // 特殊处理只能暂时关闭的频道
	{
		if(me->query_temp("block_msg/"+arg))
			me->set_temp("block_msg/"+arg,0);
		else
			me->set_temp("block_msg/"+arg,1);
		write("ok.\n");
		return 1;
	}

	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
		write("关闭 " + arg + " 频道。\n");
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		return 1;
	} else {
		write("要打开某个频道只要用该频道说话即可。\n");
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式：tune [<频道名称>]

这个指令让你选择是否要收听某一频道的讯息，如
果没有指定频道名称，就会列出你目前收听中的频
道，如果指定了频道，原来收听中的就会关掉，反
之打开。

如果你对一个没有收听中的频道讲话，会自动将它
打开。要对一个频道讲话，只要用：

<频道名称> <讯息> ....

目前可用的频道：  
    chat            闲聊专用。
    rumor           谣言频道。
    menpai(mp)      门派频道，此频道只有同门
                    派的人能看到。
    paimai          拍卖大会专用频道
    psell           个人叫卖专用频道

HELP
	);
	return 1;
}

